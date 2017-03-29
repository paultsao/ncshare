<?php
/**
 * @file
 * widget.inc.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('NCShare Widget'),
  'description' => t('Social sharing widget'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Miscellaneous'),
);

/**
 * Output function for the node content type label.
 */
function ncshare_widget_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? clone($context->data) : NULL;
  $block = new stdClass();
  $block->module = 'ncshare';
  $block->delta = $node->type;

  $bundles = variable_get('ncshare_bundles', array());
  if (!empty($bundles[$node->type]) && $bundles[$node->type]) {
    $block->title = "Social";
    $block->content = theme('ncshare_widget', array(
      'node' => $node,
    ));
  }

  return $block;
}

/**
 * Returns the administrative title for a type.
 */
function ncshare_widget_content_type_admin_title($subtype, $conf, $context) {
  return t('NCShare Widget');
}

/**
 * Returns an edit form for custom type settings.
 */
function ncshare_widget_content_type_edit_form($form, &$form_state) {
  // Provide a blank form so we have a place to have context setting.
  return $form;
}
