<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">

    <title>HomeWork #10 | Part 1 | PHP Course</title>
  </head>
  <body>
    <div class="container">
        <h3 class="mb-3 text-danger">
            TOP-500 Most Popular Domains
        </h3>
        <?php $top500 = array_slice($domainsRecords, 0, 500) ?>
        <?php if(count ($top500) > 0): ?>
            <table class="table table-sm table-hover">
                <thead>
                    <tr>
                        <th scope="col">#</th>
                        <th scope="col">Domain</th>
                        <th scope="col">IP-address</th>
                        <th scope="col">Rank</th>
                        <th scope="col">Src.</th>
                        <th scope="col">Last checked</th>
                    </tr>
                </thead>
                <tbody>
                    <?php $i = 1 ?>
                    <?php foreach ($top500 as $domain => $rank): ?>
                        <tr>
                            <td><?= $i++ ?></td>
                            <td><a href="//<?= $domain ?>" target="__blank"><?= $domain ?></a></td>
                            <td class="text-success"><?= gethostbyname($domain) ?></td>
                            <td class="text-danger"><?= $rank ?></td>
                            <td class="text-muted">filename</td>
                            <td class="text-muted">last update</td>
                        </tr>
                    <?php endforeach ?>
                </tbody>
            </table> 
        <?php else: ?>
            <div class="alert alert-dark" role="alert">
                Sorry, no records found...
            </div>
        <?php endif ?>
    </div>
    
    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>

  </body>
</html>