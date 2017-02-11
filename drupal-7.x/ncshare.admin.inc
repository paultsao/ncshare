<?php
/**
 * @file
 * Code for the NCShare module administration.
 */

/**
 * Implements hook_form().
 */
function ncshare_admin_settings_form($form, &$form_state) {
  $options = variable_get('ncshare_sharing_options', array());
  $form['ncshare_sharing_options'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => t('Social sharing options'),
    '#theme' => 'table',
    '#header' => array(t('Label'), t('Sharing URL')),
    '#rows' => array(),
    '#description' => t('Configure the links for each service to be displayed alongside content.'),
  );

  for ($i = 0; $i < count($options) + 5; $i++) {
    $label = array(
      '#type' => 'textfield',
      '#default_value' => !empty($options[$i]['label']) ? $options[$i]['label'] : NULL,
    );

    $url = array(
      '#type' => 'textfield',
      '#default_value' => !empty($options[$i]['url']) ? $options[$i]['url'] : NULL,
    );

    $form['ncshare_sharing_options'][$i] = array(
      'label' => &$label,
      'url' => &$url,
    );

    $form['ncshare_sharing_options']['#rows'][$i] = array(
      array('data' => &$label),
      array('data' => &$url),
    );

    unset($label);
    unset($url);
  }

  $entity_info = entity_get_info('node');
  $node_bundles = array();
  foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
    $node_bundles[$bundle] = $bundle_info['label'];
  }

  $form['ncshare_bundles'] = array(
    '#title' => t('Node Types'),
    '#description' => t('Select node types for which the social widget should be enabled.'),
    '#type' => 'checkboxes',
    '#options' => $node_bundles,
    '#default_value' => variable_get('ncshare_bundles', array()),
  );

  return system_settings_form($form);
}

/**
 * Valdation for ncshare_admin_settings_form().
 */
function ncshare_admin_settings_form_validate(&$form, &$form_state) {
  foreach ($form_state['values']['ncshare_sharing_options'] as $idx => $value) {
    if (empty($value['label']) || empty($value['url'])) {
      unset($form_state['values']['ncshare_sharing_options'][$idx]);
    }
  }
}
