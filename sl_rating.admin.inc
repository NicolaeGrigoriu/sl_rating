<?php
/**
 * @file
 * Administration page for competition level.
 */
function sl_rating_competition_level() {
  $form = array();
  $levels = array(
    'level_1' => array(
      'title' => t('Nivel 1'),
      'description' => t('Competi?ie de nivel local ?i regional.')),
    'level_2' => array(
      'title' => t('Nivel 2'),
      'description' => t('Competi?ie de nivel na?ional ?i interna?ional.'),
    ),
    'level_3' => array(
      'title' => t('Nivel 3'),
      'description' => t('Competi?ie de nivel continental ?i mondial.')
    ),
  );

  $form['sl_rating'] = array('#tree' => TRUE);
  $sl_rating_points = variable_get('sl_rating', array());
  foreach ($levels as $key => $level) {
    $form['sl_rating'][$key]['item'] = array(
      '#type' => 'item',
      '#markup' => $level['title'],
      '#description' => $level['description'],
    );
    $form['sl_rating'][$key]['place_1'] = array(
      '#type' => 'textfield',
      '#title' => t('Place I'),
      '#size' => 2,
      '#maxlength' => 2,
      '#default_value' => ($sl_rating_points[$key]['place_1']) ? $sl_rating_points[$key]['place_1'] : '',
    );
    $form['sl_rating'][$key]['place_2'] = array(
      '#type' => 'textfield',
      '#title' => t('Place II'),
      '#size' => 2,
      '#maxlength' => 2,
      '#default_value' => ($sl_rating_points[$key]['place_2']) ? $sl_rating_points[$key]['place_2'] : '',
    );
    $form['sl_rating'][$key]['place_3'] = array(
      '#type' => 'textfield',
      '#title' => t('Place III'),
      '#size' => 2,
      '#maxlength' => 2,
      '#default_value' => ($sl_rating_points[$key]['place_3']) ? $sl_rating_points[$key]['place_3'] : '',
    );
  }

  return system_settings_form($form);
}
