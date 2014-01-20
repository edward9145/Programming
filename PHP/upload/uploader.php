<?php
function fileext($file_name){
	$ext = "";
	$dot = strrpos($file_name, ".");
	if ($dot) $ext = substr($file_name, $dot+1, strlen($file_name) - $dot);
	return strtolower($ext);
}
/*
	echo $_POST["para"];
	echo $_POST["token"];
	print_r($_POST);  // debug  $_POST
	print_r($_FILES); // file
	print_r($file);
*/
	$file = $_FILES["file"];
	$upload_dir = "./files/";	// 设置文件保存目录
	$url_path = "http://127.0.0.1/upload/files/";  //url访问路径
	$file_type = array("jpg","gif","bmp","jpeg","png");  //设置允许上传文件的类型 
	
	if($file["error"]){
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
	
	$file_name = time() . $file["name"];  // 上传保存文件名=时间戳+原文件名
	move_uploaded_file($file["tmp_name"], $upload_dir . $file_name);
	
	echo $url_path . $file_name;
?>