<?php

error_reporting(E_ALL);
ini_set('display_errors', 'On');
date_default_timezone_set('Europe/Kiev');
$first = $_POST['date'];
$second = $_POST['dateTo'];
class DifferentDate
{
    function __construct($first, $second)
    {
        try{
            $date = new DateTime($first);
            $dateTo = new DateTime($second);
        }
        catch(Exception $e){
            $e->getMessage();
            exit(1);
            }
            
        $different = $date->diff($dateTo);
        echo $second." - ".$first. " = ".$different->y."-".$different->m."-".$different->d;
    }
}

require_once('ex2.html');