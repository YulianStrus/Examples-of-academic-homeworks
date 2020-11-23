<?php

error_reporting(E_ALL);
ini_set('display_errors', 'On');
date_default_timezone_set('Europe/Kiev');
$dat = $_POST['date'];
class Revers
{
    function __construct($dat)
    {
        return $dat;
    }
}

$date=new DateTime($dat);
require_once('ex3.html');