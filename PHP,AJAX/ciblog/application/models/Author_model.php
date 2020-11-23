<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Author_model extends CI_Model
{
	/**
	 * Save authors array
	 */
	public function save(array $autors)
	{
		$authorsIds = [];
		
		foreach ($autors as $autor)
		{
			$result = $query = $this->db->query(
				"insert into authors (name, website) values('". $this->db->escape_str($autor['name']) . "', '{$autor['website']}')"
			);

			$authorsIds[] = $this->db->insert_id();
		}

		return $authorsIds;
	}

	/**
	 * Generate faked data ONLY
	 */
    public function getFakedData($qty = 10)
    {
		$autors = [];
		
		$faker = Faker\Factory::create();

		for ($i = 0; $i < $qty; $i++) {
			$autors[] = [
				'name' => $faker->name,
				'website' => $faker->domainName,
			];
		}

		return $autors;
	}


}