<?php

/**
 * Makes all dirty job for us:
 *  1) Initializes reading files from out input directory
 *  2) Puts this data into the collection
 */
class DataManager
{
    private $sources;

    /**
     * Constructor.
     * Note, all job about reading initialized there.
     * It's not perfect way, just working way for the current stage
     */
    public function __construct(\stdClass $init)
    {
        $this->sources = [];

        // Try to use build in Iterators for your tasks solutions, everytime
        $filesIterator = new FilesystemIterator($init->dir);

        // Going through every file in the specified folder
        foreach ($filesIterator as $fileinfo) {
            // Build Reader Class Name
            $reader = sprintf("%sReader", ucfirst($fileinfo->getExtension()));
            if (class_exists($reader)) {
                // if reader class exists
                $this->addSource(
                    // create new reader object, and try to read this sourse
                    new $reader($fileinfo->getPathname())
                );
            }
        }
    }

    private function addSource(Readable $src)
    {
        // simply adds Readable objects into the collection (simple array there)
        $this->sources[] = $src;
    }

    public function getAll()
    {
        $result = [];
        
        foreach ($this->sources as $src) {
            /**
             * We want use next output format of the array:
             *  domain:rank
             * 	stock.adobe.com:6.85
             * 
             * WITHOUT DUPLICATES
             */
            $result = array_merge($result, array_combine(
                array_column($src->getContent(), 'domain'),
                array_column($src->getContent(), 'rank')
            ));
            
        }

        return $result;
        
    }

}
