<?php

/**
 * Theme ublock more info block.
 */
function theme_ublock_more_info($vars) {
  $output = '';

  $user = $vars['user'];

  $output .= '<h3>' . $user->name . '</h3>';

  if (!empty($user->picture)) {
    $image_data = array(
      'path' => $user->picture->uri,
      'style_name' => 'thumbnail',
    );

    $output .= theme('image_style', $image_data);
  }

  $output .= '<div id="ublock-more-info-more-info-wrapper">';
    $output .= l(t('More info'), 'user-more-info/' . $user->uid . '/nojs', array('attributes' => array('class' => array('use-ajax'))));
  $output .= '</div>';

  return $output;
}

/**
 * Theme ublock more info more info.
 */
function theme_ublock_more_info_more_info($vars) {
  $output = '';

  $user = $vars['user'];
  $fields = $vars['fields'];

  foreach ($fields as $field_name => $label) {
    $field_items = field_get_items('user', $user, $field_name);
    if ($field_items) {
      $rendered_field = render(field_view_value('user', $user, $field_name, $field_items[0]));
      if (!empty($rendered_field)) {
        $output .= '<strong>' . $label . ':</strong> '. $rendered_field . '<br />';
      }
    }
  }

  return $output;
}