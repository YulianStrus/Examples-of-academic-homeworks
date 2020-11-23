<?php

/**
 * Main configuration file
 */
return (object)[
    // Application bootstrap options
    'bootstrap' => (object)[
        'classes' => "classes/%s.php",
    ],
    // Input file settings
    'input' => (object)[
        'dir' => "input/original",
    ],
]; 
