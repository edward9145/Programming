<?php
error_reporting(E_ALL);

include_once 'db.php';

	$update_app_sql = "UPDATE yk_app SET name='$_POST[name]', description='$_POST[description]', version='$_POST[version]', developer='$_POST[developer]', copyright='$_POST[copyright]', contact='$_POST[contact]' where id='$_POST[id]'";

	$result = mysql_query($update_app_sql);

	mysql_close($con);

	header("location: manage.php");	
?>
