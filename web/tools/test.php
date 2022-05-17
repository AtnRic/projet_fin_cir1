<?php
//$cli = `../.../c/Solution1/main3.exe 1 a`;
//exec('../.../c/Solution1/main3.exe', $output, $result_code);
//$out=" ";
//exec("../.../c/Solution1/main4.exe 125 70", $out);
//print_r($out);

//var_dump($output);

//var_dump($result_code);



// create FFI object, loading libc and exporting function printf()
$ffi = FFI::cdef(
    "int printf(const char *format, ...);", // this is a regular C declaration
    "libc.so.6");
// call C's printf()
$ffi->printf("Hello %s!\n", "world");

