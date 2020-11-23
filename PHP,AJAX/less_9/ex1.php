<?php

error_reporting(E_ALL);
ini_set('display_errors', 'On');
date_default_timezone_set('Europe/Kiev');
$number = $_POST['fact'];
class Factorial
{
    function __construct($fact)
    {
        $factorial = 1;
        for ($i = 1; $i <= $fact; ++$i)
            $factorial *= $i;
        echo "!".$fact."=".$factorial;
    }
}
require_once('ex1.html');