@rem #------------------------------------------------------------------------------
@rem #
@rem #	xeij_control.bat
@rem #
@rem #	JP:
@rem #		XEiJ $B>e$G<B9T$5$l$F$$$k(J X68K $B$K;XDj$N3d$j9~$_$rAw?.$7$^$9!#(J
@rem #
@rem #	EN:
@rem #		Sends the specified interrupt to the X68K running on XEiJ.
@rem #
@rem #------------------------------------------------------------------------------
@rem #
@rem #	Copyright (C) 2022 Yosshin(@yosshin4004)
@rem #
@rem #	Licensed under the Apache License, Version 2.0 (the "License");
@rem #	you may not use this file except in compliance with the License.
@rem #	You may obtain a copy of the License at
@rem #
@rem #	    http://www.apache.org/licenses/LICENSE-2.0
@rem #
@rem #	Unless required by applicable law or agreed to in writing, software
@rem #	distributed under the License is distributed on an "AS IS" BASIS,
@rem #	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
@rem #	See the License for the specific language governing permissions and
@rem #	limitations under the License.
@rem #
@rem #------------------------------------------------------------------------------

@rem #
@rem # msys $B$J$I$N4D6-$G$O(J XEiJ $B$NL>A0IU$-%Q%$%W$KD>@\%"%/%;%9$G$-$J$$$,!"(J
@rem # cmd.exe $B$r5/F0$7$FK\%P%C%A$r7PM3$9$k$3$H$G$3$NLdBj$r2sHr$G$-$k!#(J
@rem #
@rem # usage:
@rem #	xeij_control.bat <interrupt>
@rem #

@echo %* > \\.\pipe\XEiJControl

