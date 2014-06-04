<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Apps Manage Login</title>
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

<h1> Apps Manage Login</h1>

<hr>

<form class="form-horizontal" role="form" method="POST" action="manage.php">
	
	<div class='form-group'>
		<label class='col-sm-2 control-label'>username</label>
		<div class='col-sm-5'>
		<input type='text' name='username' class='form-control'> 
		</div>
	</div>

	<div class='form-group'>
		<label class='col-sm-2 control-label'>password</label>
		<div class='col-sm-5'>
		<input type='password' name='password' class='form-control'> 
		</div>
	</div>

	<div class='form-group'>
		<div class='col-sm-offset-2 col-sm-5'>
		<input type='submit' class='btn btn-success'>
		</div>
	</div>
</form>
</div>

</body>
</html>
