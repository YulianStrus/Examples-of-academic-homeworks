<?php $this->load->view('partials/jumbotron') ?>
<?php $this->load->view('partials/actual') ?>

<div class="row">
  <div class="col-md-8 blog-main">
    <h3 class="pb-4 mb-4 font-italic border-bottom">
      <?= $content ?>
    </h3>

    <?php if (count($posts) > 0): ?>
      <?php foreach ($posts as $post): ?>
        <div class="blog-post">
          <h2 class="blog-post-title">
            <?= $post->title ?>
          </h2>
          <p class="blog-post-meta"><?= $post->published_at ?> by <a href="#"><?= $post->published_by ?></a></p>
          <p>Cum sociis natoque penatibus et magnis <a href="#">dis parturient montes</a>, nascetur ridiculus mus. Aenean eu leo quam. Pellentesque ornare sem lacinia quam venenatis vestibulum. Sed posuere consectetur est at lobortis. Cras mattis consectetur purus sit amet fermentum.</p>
          <blockquote>
            <p>Curabitur blandit tempus porttitor. <strong>Nullam quis risus eget urna mollis</strong> ornare vel eu leo. Nullam id dolor id nibh ultricies vehicula ut id elit.</p>
          </blockquote>
          <p>Etiam porta <em>sem malesuada magna</em> mollis euismod. Cras mattis consectetur purus sit amet fermentum. Aenean lacinia bibendum nulla sed consectetur.</p>
          <p>Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor. Duis mollis, est non commodo luctus, nisi erat porttitor ligula, eget lacinia odio sem nec elit. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</p>
        </div><!-- /.blog-post -->
      <?php endforeach ?>

      <?php $this->load->view('partials/pagination') ?>

    <?php else: ?>
      <div class="alert alert-warning" role="alert">
        There is no posts found...
      </div>
    <?php endif ?>

  </div><!-- /.blog-main -->

  <?php $this->load->view('partials/aside') ?>

</div><!-- /.row -->