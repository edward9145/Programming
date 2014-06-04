<!doctype html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Apps Manage</title>
	<link href="css/bootstrap.min.css" rel="stylesheet">
	<script src="js/jquery-1.10.2.min.js"></script>
	<script src="js/bootstrap.min.js"></script>
	<script src="js/angular.min.js"></script>
</head>
<body>

<?php
	include_once 'ca.php';
	include_once 'db.php';
	include_once 'QRcode.php';
?>

<div class="container">

<h1> Apps Manage </h1>

<hr>

<a href="new.php">
<button type="button" class="btn btn-primary">
	<span class="glyphicon glyphicon-plus"></span>New App 
</button>
</a>

<br>

<table class="table">
	<thead>
		<th>id</th>
		<th>name</th>
		<th>description</th>
		<th>version</th>
		<th>developer</th>
		<th>copyright</th>
		<th>contact</th>
		<th>update_info</th>
		<th>size(byte)</th>
		<th class="pull-right">UPDATE</th>
	</thead>
	
	<tbody>

<?php

	$select_all_app_sql = "SELECT * FROM yk_app";

	$result = mysql_query($select_all_app_sql);
	$count = mysql_num_rows($result);

	while($row = mysql_fetch_array($result)){

		$select_version_sql = "SELECT * from yk_app_version where yk_app_id='$row[id]' and version='$row[version]'";

		$result_version = mysql_query($select_version_sql);
		$row_version = mysql_fetch_array($result_version);

		$img_src = "../download/$row[id]_qrcode.png";
		QRcode::png ("$row_version[url]", $img_src);

		echo "
		<tr>
		<td>$row[id]</td>
		<td>$row[name]</td>
		<td><pre>$row[description]</pre></td>
		<td>$row[version]</td>
		<td>$row[developer]</td>
		<td>$row[copyright]</td>
		<td>$row[contact]</td>
		<td><pre>$row_version[update_info]</pre></td>
		<td>$row_version[size]</td>
		<td>
			<a href='$row_version[url]'>
			<button class='btn btn-success'>
			<span class='glyphicon glyphicon-download'></span>
			</button></a>

			<a href='edit.php?app_id=$row[id]'>
			<button class='btn btn-danger pull-right'>
			<span class='glyphicon glyphicon-edit'></span>
			</button></a>

			<br>
			<img src='$img_src'>
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
