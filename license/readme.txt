﻿xdev68k に含まれるソフトウェア、および利用させて頂いているソフトウェアの
出典元とライセンス情報をまとめます。


・binutils

	オリジナルアーカイブファイル
		build_gcc/download/binutils-2.35.tar.bz2

	xdev68k 上のインストール先
		xdev68k/m68k-toolchain/

	原作者
		Free Software Foundation, Inc.

	入手元
		https://ftp.gnu.org/gnu/binutils/

	利用規約
		GNU GENERAL PUBLIC LICENSE が適用されます。
		ライセンス原文は、オリジナルアーカイブファイルに含まれています。


・gcc

	オリジナルアーカイブファイル
		build_gcc/download/gcc-10.2.0.tar.gz

	xdev68k 上のインストール先
		xdev68k/m68k-toolchain/

	原作者
		Free Software Foundation, Inc.

	入手元
		https://gcc.gnu.org/pub/gcc/releases/

	利用規約
		GNU GENERAL PUBLIC LICENSE が適用されます。
		ライセンス原文は、オリジナルアーカイブファイルに含まれています。


・libgcc/libstdc++

	オリジナルアーカイブファイル
		build_gcc/download/gcc-10.2.0.tar.gz
			gcc のフルパッケージ
		xdev68k/archive/libgcc_src.tar.gz
		xdev68k/archive/libstdc++_src.tar.gz
			gcc のフルパッケージから、依存するソースファイルだけを抜粋した
			もの。

	xdev68k 上のインストール先
		xdev68k/lib/m68k_elf/

	原作者
		Free Software Foundation, Inc.

	入手元
		https://gcc.gnu.org/pub/gcc/releases/

	利用規約
		GNU GENERAL PUBLIC LICENSE と GCC RUNTIME LIBRARY EXCEPTION が適用
		されます。ライセンス原文は、xdev68k/license/libgcc_libstdc++/ 以下
		にあります。（ライブラリファイルをバイナリ単体で配布するときは GPL
		適用になるため、ソースコードまたはその入手手段を開示する必要がある。
		ライブラリファイルをアプリケーションにリンクして利用する場合は、
		アプリケーションに GPL は伝搬しないし、ソース開示などの義務も生じ
		ない。）


・newlib

	オリジナルアーカイブファイル
		build_gcc/download/newlib-3.3.0.tar.gz

	xdev68k 上のインストール先
		xdev68k/m68k-toolchain/

	原作者
		オリジナルアーカイブファイルの COPYING.NEWLIB を参照してください。

	入手元
		ftp://sourceware.org/pub/newlib/

	利用規約
		オリジナルアーカイブファイルの COPYING.NEWLIB を参照してください。


・run68mac

	オリジナルアーカイブファイル
		xdev68k/archive/download/
			run68mac-master.zip

	xdev68k 上のインストール先
		xdev68k/run68/
			ビルド結果の実行ファイルが置かれています。

	原作者
		originally programmed by Ｙｏｋｋｏ さん
		maintained by masamic さん, Chack'n さん
		mac 対応 by GOROman さん
		その他大勢のコントリビューター

	入手元
		original 版
			Run68 Support Pages（消失）
				http://pws.prserv.net/run68/
			Run68 Support Pages からリンクされていた公式配布 URL
				https://sourceforge.net/projects/run68/
		mac 対応版
			https://github.com/GOROman/run68mac

	利用規約
		GNU GENERAL PUBLIC LICENSE が適用されます。
		ライセンス原文は、オリジナルアーカイブファイルに含まれています。


・C Compiler PRO-68K ver2.1（XC）

	オリジナルアーカイブファイル
		xdev68k/archive/download/
			XC2101.LZH
			XC2102_02.LZH

	xdev68k 上のインストール先
		xdev68k/include/xc/
			XC2102_02.LZH に含まれる INCLUDE/ 以下のファイルを取得し、小文字
			ファイル名化と、ファイル末尾の EOF 除去を行いました。
		xdev68k/lib/xc/
			XC2102_02.LZH に含まれる LIB/ 以下のファイルをコピーしました。
		xdev68k/x68k_bin
			XC2101.LZH に含まれる AR.X と DB.X をコピーしました。

	提供元
		シャープ株式会社

	入手元
		公式配布元サイトは存在しません。
		以下の URL から転載されたアーカイブが入手可能です。
		http://retropc.net/x68000/software/sharp/xc21/

	利用規約
		xdev68k/license/FSHARP/許諾条件.txt に従ってください。


・High-speed Assembler 68060 対応版 version 3.09+89

	オリジナルアーカイブファイル
		xdev68k/archive/download/
			HAS06089.LZH

	xdev68k 上のインストール先
		xdev68k/x68k_bin
			HAS06089.LZH から取り出した HAS060.X をコピーしています。

	原作者
		Y.Nakamura さん

	作者
		M.Kamada さん

	入手元
		以下の URL からアーカイブが入手可能です。
		http://retropc.net/x68000/software/develop/as/has060/

	利用規約
		HAS06089.LZH に含まれる README.DOC に従ってください。


・HLK version 3.01

	オリジナルアーカイブファイル
		xdev68k/archive/download/
			HLK301B.LZH

	xdev68k 上のインストール先
		xdev68k/x68k_bin
			HLK301B.LZH から取り出した hlk301.x をコピーしています。

	原作者
		SALT さん

	入手元
		以下の URL から転載されたアーカイブが入手可能です。
		http://retropc.net/x68000/software/develop/lk/hlk/

	利用規約
		HLK301B.LZH に含まれる readme.doc に従ってください。


・g2as.x g2lk.x

	オリジナルアーカイブファイル
		xdev68k/archive/download/
			G3_20.LZH

	xdev68k 上のインストール先
		xdev68k/x68k_bin
			G3_20.LZH から取り出した g2as.x g2lk.x をコピーしています。

	原作者
		Y.Nakamura さん

	作者
		Ｃharlie さん

	入手元
		以下の URL から転載されたアーカイブが入手可能です。
		http://retropc.net/x68000/software/develop/c/gcc2/

	利用規約
		G3_20.LZH に含まれる readme.doc に従ってください。


・Project C Library LIBC 1.1.32A ぱっち DON 版

	ファイル
		include/xdev68k/doscall.inc
		include/xdev68k/fefunc.inc
		include/xdev68k/iocscall.inc

	原作者
		Project LIBC Group
		立花えり子 さん

	作者
		DON さん

	入手元
		以下の URL から転載されたアーカイブが入手可能です。
		http://retropc.net/x68000/software/develop/lib/libcdon/

	利用規約
		public domain です。


・上記以外

	ファイル
		xdev68k/util/x68k_gas2has.pl
		xdev68k/build_m68k-toolchain.sh
		xdev68k/build_x68k-libgcc.sh
		xdev68k/install_xdev68k-utils.sh

	作者
		Yosshin

	入手元
		https://github.com/yosshin4004/xdev68k/

	利用規約
		Apache License, Version 2.0 が適用されます。
		ライセンスの原文は、
			xdev68k/license/xdev68k/LICENSE
		です。



