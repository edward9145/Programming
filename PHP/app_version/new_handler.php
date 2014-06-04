<?php
error_reporting(E_ALL);

include_once 'db.php';

	$insert_app_sql = "INSERT INTO yk_app (id, name, description, version, developer, copyright, contact) VALUES ('$_POST[id]','$_POST[name]','$_POST[description]','$_POST[version]','$_POST[developer]','$_POST[copyright]','$_POST[contact]')";

	$result = mysql_query($insert_app_sql);

	mysql_close($con);

	header("location: manage.php");	
?>
