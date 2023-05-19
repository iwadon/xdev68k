*
* 実行ファイルのエントリポイントとなるソースコード
*
*
*・このソースコードがエントリポイントになれる条件
*
*	次の (1) または (2) のどちらか一方が満たされて居ればよい。
*
*	1) .end ディレクティブが指定されている
*	2) リンクリストの先頭に指定されている
*
*
*・エントリポイントのラベル名は __main とすることを推奨
*
*	エントリポイントを含むオブジェクトファイルをアーカイブファイルで提供
*	する場合を想定し、エントリポイントのラベル名を __main にすることが推奨
*	されている。
*
*	__main が推奨される経緯は少々複雑である。順を追って説明すると次のよう
*	になる。
*
*	X68K のリンカは、アーカイブファイルが指定された場合、その中に含まれる
*	オブジェクトファイルのうち、プログラム中から参照されるもののみをリンク
*	対象とする。
*
*	実行ファイルのエントリポイントとなるラベルは通常どこからも参照されない
*	ので、そのラベルを含むオブジェクトファイルはリンク対象から除外されて
*	しまう。エントリポイントが認識できない場合、リンカは最初のオブジェクト
*	ファイルをエントリポイントとするので、起動不能の実行ファイルが生成され
*	てしまう。
*
*	この問題を回避するため、X68K 対応コンパイラは、main() 関数を含むオブ
*	ジェクトファイルには、外部参照ラベルとして __main も追加でリンクする
*	ことを要求する。エントリポイントのラベル名も __main であれば、リンク
*	対象から除外されることが回避される。
*	xdev68k でも、x68k_gas2has.pl で同様の対応を行っている。
*

	.cpu 68000
	.include doscall.inc
	.include iocscall.inc

	.text
	.even

	.xdef		__main
	.xref		_asmMain

*
* エントリポイントのラベル名は __main とすることを推奨
*
__main:
	move.l	a4, -(sp)		* プログラムの実行開始アドレス
	move.l	a3, -(sp)		* 環境のアドレス
	move.l	a2, -(sp)		* コマンドラインのアドレス
	move.l	a1, -(sp)		* プログラムの終わり+1 のアドレス
	move.l	a0, -(sp)		* メモリ管理ポインタのアドレス
	jbsr	_asmMain		* アプリケーション main を呼び出す
	add.l	#4*5,sp

	move.w	d0,-(sp)
	dc.w	__EXIT2

*
* __main をエントリポイントにするため .end ディレクティブが必要
*
	.end		__main
