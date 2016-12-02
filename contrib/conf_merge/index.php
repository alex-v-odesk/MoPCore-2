<?php
/*
 * Project Name: Config File Merge For WoW Server.
 * Date: 01.01.2012 Alpha Version (0.0.0a).
 * Update: 05.05.2014 Beta Version (0.0.0b)
 * Author: JustACore.
 * Copyright: JustACore.
 * License: GNU General Public License v3(GPL)
 */
?>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1251">
<FORM enctype="multipart/form-data" ACTION="merge.php" METHOD="POST">
Dist File
<br />
<INPUT name="File1" TYPE="file">
<br />
Current Conf File
<br />
<INPUT name="File2" TYPE="file">
<br />
<INPUT TYPE=RADIO NAME="eol" VALUE="0" CHECKED >Win32 -
<INPUT TYPE=RADIO NAME="eol" VALUE="1"         >UNIX/Linux
<br />
<INPUT TYPE="submit" VALUE="Submit">
<br />
If you have any custom settings, such as from patches,
<br />
make sure they are at the bottom of the file following
<br />
this block (add it if it's not there)
<br />
###############################################################################
<br />
# Custom
<br />
###############################################################################
<br />
<br />

</FORM>
