<?php
defined('BASEPATH') OR exit('No direct script access allowed');

require_once 'BaseController.php';

class Home extends BaseController
{
	public function index()
	{
		$this->load->model('Post_model');

		$this->render->title = "Home Page";
		$this->render->content = "Show Home Page";
		$this->render->page = $this->getView(__CLASS__, __FUNCTION__);
		
		$this->render->posts = $this->Post_model->getPosts();

		$this->render();
	}
}
