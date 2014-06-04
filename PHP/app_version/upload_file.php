<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
</head>
<body>
<form enctype="multipart/form-data" method="POST" action="upload_handler.php">
  appId  <input type="text" name="app_id" value="jbq" required/> <br/>
  appName  <input type="text" name="app_name"value="益康运动" required/> <br/>
  appDescription  <input type="text" name="app_description"/> <br/>
  appVersion  <input type="text" name="app_version" value="1.0.0" required/> <br/>
  <input type="hidden" name="MAX_FILE_SIZE" value="20000000"/><!--限制文件大小20M-->
  File  <input type="file" name="file" required/><br/>
  <input type="submit"/>
</form>
</body>
</html>
