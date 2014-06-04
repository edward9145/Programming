<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
	<title>New App</title>
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

<h1> <a href="manage.php">Apps Manage</a> &gt;&gt; New App</h1>

<hr>

<form class="form-horizontal" role="form" method="POST" action="new_handler.php">

<?php
	echo "
		<div class='form-group'>
			<label class='col-sm-2 control-label'>id</label>
			<div class='col-sm-5'>
			<input type='text' name='id' class='form-control' placeholder='id should be unique!'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>name</label>
			<div class='col-sm-5'>
			<input type='text' name='name' class='form-control'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>description</label>
			<div class='col-sm-9'>
			<textarea name='description' class='form-control'></textarea>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>version</label>
			<div class='col-sm-5'>
			<input type='text' name='version' class='form-control'> 
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>developer</label>
			<div class='col-sm-5'>
			<input type='text' name='developer' class='form-control'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>copyright</label>
			<div class='col-sm-5'>
			<input type='text' name='copyright' class='form-control'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>contact</label>
			<div class='col-sm-5'>
			<input type='text' name='contact' class='form-control'>
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
