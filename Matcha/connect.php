<?php

include('config/database.php');

function Connect()
{
	return new PDO("mysql:host=localhost; dbname=matcha", "root", "admin");
}

?>