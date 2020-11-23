<?php
defined('BASEPATH') OR exit('No direct script access allowed');

require_once 'BaseController.php';

class Category extends BaseController {

	public function show($alias)
	{
		$this->render->title = $alias;
		$this->render->content = "Show all posts from category={$alias}";
		$this->render->page = $this->getView(__CLASS__, __FUNCTION__);

		$this->render();
	}
}
