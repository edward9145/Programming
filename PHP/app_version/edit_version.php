<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Edit Version</title>
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
Edit Version
</h1>

<hr>

<form class="form-horizontal" role="form" method="POST" action="edit_version_handler.php?app_id=<?=$_GET['app_id']?>" enctype="multipart/form-data">

	<input type="hidden" name="MAX_FILE_SIZE" value="20000000"/><!--限制文件大小20M-->

<?php
	$select_version_sql = "SELECT * FROM yk_app_version where id='$_GET[id]' order by ts desc";

	$result = mysql_query($select_version_sql);
	$row = mysql_fetch_array($result);

		echo "
		<div class='form-group'>
			<label class='col-sm-2 control-label'>id</label>
			<div class='col-sm-5'>
			<input type='text' class='form-control' name='id' value='$row[id]' readonly='readonly'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>update_info</label>
			<div class='col-sm-9'>
			<textarea name='update_info' class='form-control' rows='5'>$row[update_info]</textarea>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>version</label>
			<div class='col-sm-5'>
			<input type='text' class='form-control' name='version' value='$row[version]' readonly='readonly'>
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

	mysql_close($con);
?>

</form>

</div>

</body>
</html>
