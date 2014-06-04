<?php
error_reporting(E_ALL);
	
	$con = mysql_connect("127.0.0.1:3306", "yikang", "77yyggvv55ttggbb");
	if (!$con) die('Could not connect: ' . mysql_error());
	
	mysql_select_db("yikang", $con);
	mysql_query("set names 'utf8'");
	
//	mysql_close($con);
/*	
	$select_app_sql = "SELECT * FROM yk_app where id='$_POST[id]'";
	$insert_app_sql = "INSERT INTO yk_app (id, name, description, version, developer, copyright, contact) VALUES ('$_POST[id]','$_POST[name]','$_POST[description]','$_POST[version]','$_POST[developer]','$_POST[copyright]','$_POST[contact]')";
	$update_app_sql = "UPDATE yk_app SET name='$_POST[name]', description='$_POST[description]', version='$_POST[version]', developer='$_POST[developer]', copyright='$_POST[copyright]', contact='$_POST[contact]' where id='$_POST[id]'";

	$insert_version_sql = "INSERT INTO yk_app_version (id, yk_app_id, update_info, version, size, url) VALUES (UUID(), '$_POST[app_id]', '$_POST[update_info]', '$_POST[version]', '$file_size', '$access_url')";
	$update_version_sql = "UPDATE yk_app_version SET update_info='$_POST[update_info]', version='$_POST[version]', size='$file_size', url='$access_url' where id='$_POST[id]'";
*/
?>
