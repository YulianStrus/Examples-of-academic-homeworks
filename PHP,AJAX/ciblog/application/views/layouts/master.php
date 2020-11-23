<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title><?= $title ?> · itStep Blog · CodeIgniter Based</title>
    <!-- Bootstrap core CSS -->
    <link href="<?= site_url('assets/css/bootstrap.min.css') ?>" rel="stylesheet">
    <!-- Favicons -->
    <link rel="icon" href="<?= site_url('assets/img/icons/blog-icon.png') ?>" sizes="32x32" type="image/png">
    <!-- Custom styles for this template -->
    <link href="https://fonts.googleapis.com/css?family=Playfair+Display:700,900" rel="stylesheet">
    <!-- Custom styles for this template -->
    <link href="<?= site_url('assets/css/blog.css') ?>" rel="stylesheet">
  </head>
  <body>
    <div class="container">
      <?php $this->load->view('partials/header') ?>
      <?php $this->load->view('partials/nav') ?>
    </div>
    <main role="main" class="container">
      <?php //  $this->load->view('pages/home/index') ?>
      <?php $this->load->view($page) ?>
    </main><!-- /.container -->
    <?php $this->load->view('partials/footer') ?>
  </body>
</html>