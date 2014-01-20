<form enctype="multipart/form-data" method="POST" action="uploader.php">
  para  <input type="text" name="para"/> <br/>
  token  <input type="text" name="token"/>
  <input type="hidden" name="MAX_FILE_SIZE" value="2000000"/><!--限制文件大小2M--><br/>
  File  <input type="file" name="file"/><br/>
  <input type="submit"/>
</form>