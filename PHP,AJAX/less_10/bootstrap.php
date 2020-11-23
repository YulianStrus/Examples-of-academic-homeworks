<?php

error_reporting(E_ALL);

ini_set('display_errors', 'On');

ini_set('memory_limit', '5G');

date_default_timezone_set('Europe/Kiev');

//Load main config file here
$config = include_once 'config.php';

// Classes loader
spl_autoload_register(function($className) use ($config) {
    require_once sprintf(
        $config->bootstrap->classes, $className
    );
});

/**
 * DataManager - a class that does all the "black" work 
 * behind the scenes:
 * 
 *  1) browsing a directory with files
 *  2) finds a class-reader for each file type
 *  3) loads data from each file depending on its type
 *  4) puts this data into the collection for further work
 */
$dataManager = new DataManager(
    $config->input
);
