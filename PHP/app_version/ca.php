<?php
	$username = 'yikang';
	$password = 'hlyk2014';

	session_start();

	if($_SESSION[login]){
		; // login success
	}
	else if($_POST[username] == $username && $_POST[password] == $password){
		$_SESSION[login] = true; // login success
	}
	else{
		header("location: login.php");	
	}
?>
