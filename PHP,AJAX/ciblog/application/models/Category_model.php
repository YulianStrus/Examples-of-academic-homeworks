<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Category_model extends CI_Model
{
	/**
	 * Save categories array
	 */
	public function save(array $categories)
	{
		$catIds = [];
		
		foreach ($categories as $category)
		{
			$this->db->query(
				"insert into categories (name, display) values('{$category['name']}', '{$category['display']}')"
			);

			$catIds[] = $this->db->insert_id();
		}

		return $catIds;

	}

	/**
	 * Generate faked data ONLY
	 */
    public function getFakedData($qty = 10)
    {
        $items = [];

		$faker = Faker\Factory::create();

		$display = [
			0 => 'no',
			1 => 'yes'
		];

		for ($i = 0; $i < $qty; $i++) {
			$items[] = [
				'name' => $faker->word,
				'display' => $display[rand(0,1)]
			];
		}
		
        return $items;
	}


}