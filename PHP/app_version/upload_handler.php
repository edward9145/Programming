<?php
error_reporting(E_ALL);

function fileext($file_name){
	$ext = "";
	$dot = strrpos($file_name, ".");
	if ($dot) $ext = substr($file_name, $dot+1, strlen($file_name) - $dot);
	return strtolower($ext);
}
/*
	print_r($_POST);  // debug  $_POST
	print_r($_FILES); // file
	print_r($file);
*/
	$file = $_FILES["file"];
	$upload_dir = "../download/";	// 设置文件保存目录
	$url_path = "http://www.hualuyikang.com/download/";  //url访问路径
	$file_type = array("jpg","gif","bmp","jpeg","png","apk","ipa");  //设置允许上传文件的类型 
	
	if($file["error"]){
		echo $file["error"];
		echo "file_upload_error";
		exit();
	}
	if(!in_array(fileext($file["name"]), $file_type)){
		echo "file_type_error";
		exit();
	}
	if(!file_exists($upload_dir)){
		mkdir($upload_dir);
	}
	
	$file_size = $file["size"];
	$file_name = $file["name"];  // 上传保存文件名=原文件名
	move_uploaded_file($file["tmp_name"], $upload_dir . $file_name);
	
//	echo $upload_dir.$file_name;

	$access_url = $url_path . $file_name;
	echo $access_url;
	
?>
