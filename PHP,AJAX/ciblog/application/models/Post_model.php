<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Post_model extends CI_Model
{
	public function getPosts()
	{
		return [
			(object)[
				'title' => 'Sample blog post',
				'published_at' => 'February 11, 2013',
				'published_by' => 'Mark Baum',
			],
			(object)[
				'title' => 'Another blog post',
				'published_at' => 'December 23, 2013',
				'published_by' => 'Jacob Rosso',
			],
			(object)[
				'title' => 'New feature',
				'published_at' => 'March 05, 2013',
				'published_by' => 'Chris Donnel',
			],
		];
	}
	/**
	 * Save POSTS array
	 */
	public function save(array $posts)
	{
		foreach ($posts as $post)
		{
			$this->db->query(
				"insert into posts (title, author_id, category_id) values('{$post['title']}', {$post['author_id']}, {$post['category_id']})"
			);
		}
	}

	/**
	 * Generate faked data ONLY
	 */
    public function getFakedData(array $catIds, array $authorsIds)
    {
		$faker = Faker\Factory::create();

		$posts = [];

		for ($i = 0; $i < 10; $i++) {
			$posts[] = [
				'title' => $faker->words(5, true),
				'author_id' =>  $authorsIds[array_rand($authorsIds)],
				'category_id' => $catIds[array_rand($catIds)],
			];
		}

		return $posts;

	}


}