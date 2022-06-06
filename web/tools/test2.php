<?php
include "_main_tools.php";
$theme=2;
$string_theme=GetTheme($theme);
$random=rand(min:0,max:1001);
$name="$string_theme#$random";
echo $name;
?>