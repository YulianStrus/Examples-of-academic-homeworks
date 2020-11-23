<?php

/**
 * Read txt files
 */
class TxtReader implements Readable
{
    /**
     * SplFileObject instance
     * 
     */
    private $file;

    /**
     * Constructor
     */
    public function __construct($filePath)
    {
        $this->file = new SplFileObject($filePath);
    }

    /**
     * Get resourse unique identifier
     * It can be used in the future, for some system goals
     */
    public function getSrcId()
    {
        return $this->file->getFilename();
    }

    public function getSrcInfo()
    {
        return $this->file;
    }

    /**
     * Load content from a file
     */
    public function getContent()
    {
        $lines = [];

        foreach ($this->file as $row) {
            // extract row into the variable
            list($num, $domain, $rank) = explode(
                ";", str_replace('"', '', $row)
            );

            // build a simple array from row attributes
            $lines[] = [
                'domain' => trim($domain),
                'rank' => (float)$rank,
            ];
            
        }

        return $lines;
    }

}
