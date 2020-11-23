<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Welcome extends CI_Controller
{
	public function faker()
	{
		//$this->output->enable_profiler(TRUE);

		$this->load->model('Category_model');
		$this->load->model('Author_model');
		$this->load->model('Post_model');
		
		$catIds = $this->Category_model->save(
			$this->Category_model->getFakedData()
		);

		$authorsIds = $this->Author_model->save(
			$this->Author_model->getFakedData()
		);
		
		$posts = $this->Post_model->getFakedData(
			$catIds, $authorsIds
		);

		/*
		$this->Post_model->save($posts);
		
		$query = $this->db->query("SELECT * FROM `posts`");

		echo "<pre>";
		print_r($query->result());
		exit; 
		*/

	}
	public function index()
	{
		$this->load->view('welcome_message');
	}
}
