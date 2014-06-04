<?php
error_reporting(E_ALL);

include_once 'upload_handler.php';
include_once 'db.php';

	$update_version_sql = "UPDATE yk_app_version SET update_info='$_POST[update_info]', version='$_POST[version]', size='$file_size', url='$access_url' where id='$_POST[id]'";

	$result = mysql_query($update_version_sql);

	mysql_close($con);

	header("location: edit.php?app_id=$_GET[app_id]");	
?>
