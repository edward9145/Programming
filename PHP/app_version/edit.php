<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
	<title>App Edit</title>
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

<h1> <a href="manage.php">Apps Manage</a> &gt;&gt; App Edit </h1>

<hr>

<form class="form-horizontal" role="form" method="POST" action="edit_handler.php">

<?php
	$select_app_sql = "SELECT * FROM yk_app where id='$_GET[app_id]'";
	$result_app = mysql_query($select_app_sql);
	$row_app = mysql_fetch_array($result_app);

	$select_version_sql = "SELECT version FROM yk_app_version where yk_app_id='$_GET[app_id]' order by ts desc";
	$result_version = mysql_query($select_version_sql);

	echo "
		<div class='form-group'>
			<label class='col-sm-2 control-label'>id</label>
			<div class='col-sm-5'>
			<input type='text' name='id' class='form-control' value='$row_app[id]' readonly='readonly'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>name</label>
			<div class='col-sm-5'>
			<input type='text' name='name' class='form-control' value='$row_app[name]'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>description</label>
			<div class='col-sm-9'>
			<textarea name='description' class='form-control'>$row_app[description]</textarea>
			</div>
		</div>
		";

		echo "
		<div class='form-group'>
			<label class='col-sm-2 control-label'>version</label>
			<div class='col-sm-5'>
			<select name='version' class='form-control'>
		";

		while($row = mysql_fetch_array($result_version)){
			if($row[version] == $row_app[version])
				echo "<option value='$row[version]' selected='selected'>$row[version]</option>";
			else
				echo "<option value='$row[version]'>$row[version]</option>";
		}

		echo "
			</select>
			</div>
		</div>
		";

		echo "
		<div class='form-group'>
			<label class='col-sm-2 control-label'>developer</label>
			<div class='col-sm-5'>
			<input type='text' name='developer' class='form-control' value='$row_app[developer]'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>copyright</label>
			<div class='col-sm-5'>
			<input type='text' name='copyright' class='form-control' value='$row_app[copyright]'>
			</div>
		</div>

		<div class='form-group'>
			<label class='col-sm-2 control-label'>contact</label>
			<div class='col-sm-5'>
			<input type='text' name='contact' class='form-control' value='$row_app[contact]'>
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

<a href="new_version.php?app_id=<?=$_GET['app_id']?>">
<button type="button" class="btn btn-warning">
	<span class="glyphicon glyphicon-plus"></span>New Version
</button>
</a>

<br>

<table class="table">
	<thead>
		<th>update_info</th>
		<th>version</th>
		<th>size(byte)</th>
		<th>url</th>
		<th></th>
		<th>DELETE</th>
		<th>UPDATE</th>
	</thead>
	
	<tbody>

<?php

	$select_all_version_sql = "SELECT * FROM yk_app_version where yk_app_id='$_GET[app_id]' order by ts desc";

	$result = mysql_query($select_all_version_sql);
	$count = mysql_num_rows($result);

	while($row = mysql_fetch_array($result)){

		echo "
		<tr>
		<td>$row[update_info]</td>
		<td>$row[version]</td>
		<td>$row[size]</td>
		<td>$row[url]</td>
		<td>
			<a href='$row[url]'>
			<button class='btn btn-success'>
			<span class='glyphicon glyphicon-download'></span>
			</button></a>
		</td>

		<td>
		<a onclick='if(confirm(\"delete version $row[version]?\")) window.location=\"delete_version.php?app_id=$_GET[app_id]&id=$row[id]\";'>
			<button class='btn btn-info'>
			<span class='glyphicon glyphicon-trash'></span>
			</button></a>
		</td>

		<td>
			<a href='edit_version.php?app_id=$_GET[app_id]&id=$row[id]'>
			<button class='btn btn-danger'>
			<span class='glyphicon glyphicon-edit'></span>
			</button></a>
		</td>
		</tr>
		";

//		print_r($row);
//		print_r($row_version);
	}

	mysql_close($con);
?>

	</tbody>
</table>

</div>

</body>
</html>
