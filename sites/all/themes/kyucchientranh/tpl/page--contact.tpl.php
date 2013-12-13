<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Magicbox | Contact</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

</head>
<body>
<div class="main">
  <div class="header">
    <div class="header_resize">
      <div class="searchform">
        <form id="formsearch" name="formsearch" method="post" action="#">
          <span>
         
          </span>
         
        </form>
      </div>
      <div class="logo">
        <h1><a href="index.html">Magic<span>box</span> <small>Company Slogan Here</small></a></h1>
      </div>
      <div class="clr"></div>
    
      <div class="menu_nav">
       <?php print theme('links__system_main_menu', array(
          'links' => $main_menu,
          'attributes' => array(
            'id' => 'main-menu-links',
            'class' => array('links', 'clearfix'),
          ),
          'heading' => array(
            'text' => t('Main menu'),
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>
      </div>
      <div class="clr"></div>
      <div class="slider">
        <?php print render ($page['highlighted']); ?>
      <div class="clr"></div>
    </div>
  </div>
      </div>
  <div class="content">
    <div class="content_resize">
      <div class="mainbar" style= ="">
        <div class="article">
          <div class="clr"></div>
          <?php print $messsage; ?>
         <?php print render ($page['content']); ?>
        </div>
      </div>
        
     
    </div>
       <div class="sidebar">
            <div class="gadget">
           <?php print render ($page['sidebar']); ?>
            </div>
       </div>
      
      <div class="clr"></div>
  </div>
  <div class="fbg">
   
      <?php if ($page['fcolumn1'] || $page['fcolumn2'] || $page['fcolumn3']): ?>
         <div class="fbg_resize">
        <?php print render($page['fcolumn1']); ?>
        <?php print render($page['fcolumn2']); ?>
        <?php print render($page['fcolumn3']); ?>
       <!-- /#footer-columns -->
    <?php endif; ?>
      
     
      <div class="clr"></div>
 
  </div>
  <div class="footer">
    <div class="footer_resize">
      <p class="lf">&copy; Copyright <a href="#">MyWebSite</a>.</p>
      <p class="rf">Design by Dream <a href="http://www.dreamtemplate.com/">Web Templates</a></p>
      <div style="clear:both;"></div>
    </div>
  </div>
</div>
<div align=center>This template  downloaded form <a href='http://all-free-download.com/free-website-templates/'>free website templates</a>
</div></body>
</html>
