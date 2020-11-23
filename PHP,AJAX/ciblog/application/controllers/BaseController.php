<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class BaseController extends CI_Controller
{
	protected $render;

	public function __construct()
	{
		parent::__construct();

		$this->render = new \stdClass;
	}

	protected function getView($class, $method)
	{
		return sprintf("pages/%s/%s", strtolower($class), strtolower($method));
	}

	protected function render()
	{
		$this->load->view('layouts/master', $this->render);
	}	

}
