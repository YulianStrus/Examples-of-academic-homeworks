<?php
defined('BASEPATH') OR exit('No direct script access allowed');

require_once 'BaseController.php';

class Post extends BaseController {

	public function show($id)
	{
		$this->render->title = "POST ID = {$id}";
		$this->render->content = "POST ID = {$id}";
		$this->render->page = $this->getView(__CLASS__, __FUNCTION__);

		$this->render();
	}
}
