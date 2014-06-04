<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
	<title>New Version</title>
	<link href="css/bootstrap.min.css" rel="stylesheet">
	<script src="js/jquery-1.10.2.min.js"></script>
	<script src="js/bootstrap.min.js"></script>
	<script src="js/angular.min.js"></script>
</head>
<body>

<?php
	include_once 'db.php';
?>

<div class="container">

<h1> 
<a href="manage.php">Apps Manage</a> &gt;&gt; 
<a href="edit.php?app_id=<?=$_GET['app_id']?>">App Edit</a> &gt;&gt;
New Version
</h1>

<hr>

<form class="form-horizontal" role="form" method="POST" action="new_version_handler.php?app_id=<?=$_GET['app_id']?>" enctype="multipart/form-data">

	<input type="hidden" name="MAX_FILE_SIZE" value="20000000"/><!--限制文件大小20M-->

<?php
		echo "

		<div class='form-group'>
			<label class='col-sm-2 control-label'>update_info</label>
			<div class='col-sm-9'>
			<textarea name='update_info' class='form-control' rows='5'></textarea>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>version</label>
			<div class='col-sm-5'>
			<input type='text' class='form-control' name='version'>
			</div>
		</div>

		<div class='form-group'>
			<div class='col-sm-offset-2 col-sm-5'>
			<input type='file' class='form-control' name='file' required>
			</div>
		</div>
		
		<div class='form-group'>
			<div class='col-sm-offset-2 col-sm-5'>
			<input type='submit' class='btn btn-danger'>
			</div>
		</div>

		";

?>

</form>

</div>

</body>
</html>
