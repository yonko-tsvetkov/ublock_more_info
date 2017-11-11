<?php

function ublock_more_info_get_author_deck_block() {
  if(arg(0) == 'node' && is_numeric(arg(1)) && ((arg(2) == '' || arg(2) == 'view'))) {
    $node = menu_get_object();
    if ($node->uid != 0) {
      drupal_add_library('system', 'drupal.ajax');
      $author = user_load($node->uid);
      return theme('ublock_more_info', array('user' => $author));
    }
  }
}