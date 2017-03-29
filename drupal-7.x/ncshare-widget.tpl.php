<?php
/**
 * @file
 * Default theme implementation for NCShare Widget.
 *
 * Available variables:
 * - $links: an HTML unordered list of links.
 */
?>
<div class="ncshare-widget">
  <a href="#" class="share-trigger">Share</a>
  <div class="share-links">
    <?php print render($links) ?>
  </div>
</div>
