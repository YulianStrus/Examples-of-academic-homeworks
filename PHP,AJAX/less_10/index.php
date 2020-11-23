<?php
require_once 'vendor/autoload.php';
/**
 * Front Controller.
 * All the App business logic is defined here.
 * 
 */

// Init the App 
require_once 'bootstrap.php';

// Get all records from our sources files.
$domainsRecords = $dataManager->getAll();

// Then sort them in descending order.
arsort($domainsRecords);

// Put this data into the View
require_once 'views/top-500.php';
