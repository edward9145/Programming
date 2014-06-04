<?php
error_reporting(E_ALL);

include_once 'upload_handler.php';
include_once 'db.php';

	$insert_version_sql = "INSERT INTO yk_app_version (id, yk_app_id, update_info, version, size, url) VALUES (UUID(), '$_GET[app_id]', '$_POST[update_info]', '$_POST[version]', '$file_size', '$access_url')";

	$result = mysql_query($insert_version_sql);

	mysql_close($con);

	header("location: edit.php?app_id=$_GET[app_id]");	
?>
