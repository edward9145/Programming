<?php
error_reporting(E_ALL);

include_once 'db.php';

	$delete_version_sql = "DELETE FROM yk_app_version WHERE id='$_GET[id]'";

	$result = mysql_query($delete_version_sql);

	mysql_close($con);

	header("location: edit.php?app_id=$_GET[app_id]");	
?>
