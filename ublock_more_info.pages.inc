<?php

/**
 * Get user more info.
 */
function ublock_get_author_more_info($user, $js) {
  if ($js != 'ajax') {
    drupal_goto('user/' . $user->uid);
  }
  $fields = array(
    'field_first_name' => t('First name'),
    'field_last_name' => t('Last name'),
    'field_age' => t('Age'),
  );

  $output = theme('ublock_more_info', array('user' => $user, 'fields' => $fields));

  $commands = array();
  $commands[] = ajax_command_replace('#ublock-more-info-more-info-wrapper', $output);
  return array('#type' => 'ajax', '#commands' => $commands);
}