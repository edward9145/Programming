<?php
error_reporting(E_ALL ^ E_NOTICE);
echo "start oracle connect";
$conn = oci_connect('yikang', 'G2V1VMTK', '210.77.144.233/orcl');
if (!$conn) { 
	$e = oci_error(); 
	print htmlentities($e['message']); 
	exit; 
} 
echo "connection ok!";
?>
