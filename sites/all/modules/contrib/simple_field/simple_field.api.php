<?php
/**
 * @file
 * Hooks provided by the Simple Field module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to specify custom types of simple fields.
 *
 * @return
 *   An array whose keys are simple field type names and whose values are arrays
 *   containing the keys. All optional except 'field'.
 *   - field: The Field module field type machine name.
 *   - label: The short label for this simple field type or the
 *     machine name if not specified.
 *   - help: The long description of the behavior of the simple
 *     field type or blank if not specified.
 *   - widget: The Field module widget type. Will use field default
 *     if not specified.
 *   - formatter: The Field module formatter type. Will use the field
 *     default formatter if not specified.
 *   - cardinality: The cardinality of the field. Unlimited if blank.
 *   - defaults: An array of settings to override the default Field
 *     module settings. Keyed by the type of setting.
 *     - field_settings: Settings to override values returned from calling
 *       field_info_field_settings($field_type);
 *     - instance_settings: Settings to override values returned from calling
 *       field_info_instance_settings($field_type);
 *     - widget_settings: Settings to override values returned from calling
 *       field_info_widget_settings($widget_type);
 *     - formatter_settings: Settings to override values returned from calling
 *       field_info_formatter_settings($formatter_type);
 */
function hook_simple_field_type_info() {
  return array(
    'simple_field_yesno' => array(
      // There are a ton more options for this, but they are set to defaults.
      // @see simple_field_type_info()
      'label' => t('Yes/No'),
      'help' => t('Display a set of Yes and No radio buttons to allow the user a boolean choice.'),
      'field' => 'list_boolean',
      'cardinality' => 1,
      'defaults' => array(
        'field_settings' => array(
          'allowed_values' => array(
            1 => 'Yes',
            0 => 'No',
          ),
        ),
      ),
    ),
    'simple_field_multichoice_single' => array(
      'label' => t('Multiple Choice (Choose 1 Options)'),
      'help' => t('Enter a list of options and allow the user to select a single options.'),
      'field' => 'list_text',
      'widget' => 'options_buttons',
      'cardinality' => 1,
    ),
    'simple_field_multichoice_multi' => array(
      'label' => t('Multiple Choice (Choose many Options)'),
      'help' => t('Enter a list of options and allow the user to select as many as they would like.'),
      'field' => 'list_text',
      'widget' => 'options_buttons',
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    ),
    'simple_field_short_answer' => array(
      'label' => t('Short Answer'),
      'help' => t('Allow the user to enter a single line of text.'),
      'cardinality' => 1,
      'field' => 'text',
    ),
    'simple_field_long_answer' => array(
      'label' => t('Long Answer'),
      'help' => t('Allow the user to enter a large block of text.'),
      'cardinality' => 1,
      'field' => 'text_long',
      'widget' => 'text_textarea',
    ),
    'simple_field_single_date' => array(
      'label' => t('Date'),
      'help' => t('Allow the user to enter a single Date value.'),
      'field' => 'datestamp',
      'widget' => 'date_text',
      'cardinality' => 1,
      'defaults' => array(
        'field_settings' => array(
          'granularity' => array(
            'year' => 'year',
            'month' => 'month',
            'day' => 'day',
          ),
          'tz_handling' => 'none',
        ),
        'instance_settings' => array(
          'default_value' => 'blank',
        ),
        'widget_settings' => array(
          'input_format_custom' => 'Y-m-d',
        ),
      ),
    ),
    'simple_field_date_range' => array(
      'label' => t('Date Range'),
      'help' => t('Allow the user to enter a Date range with a beginning and ending date.'),
      'field' => 'datestamp',
      'widget' => 'date_text',
      'cardinality' => 1,
      'defaults' => array(
        'field_settings' => array(
          'todate' => 'required',
          'granularity' => array(
            'year' => 'year',
            'month' => 'month',
            'day' => 'day',
          ),
          'tz_handling' => 'none',
        ),
        'instance_settings' => array(
          'default_value' => 'blank',
        ),
        'widget_settings' => array(
          'input_format_custom' => 'Y-m-d',
        ),
      ),
    ),
    'simple_field_integer' => array(
      'label' => t('Integer'),
      'help' => t('Allow the user to enter a single single integer value.'),
      'cardinality' => 1,
      'field' => 'number_integer',
    ),
  );
}

/**
 * Allow modules to add elements to the simple field form.
 *
 * This hook allows modules to provide form elements in order to allow users to
 * change field settings. The hook is only called on the module that provided
 * the simple field type, so any module looking to alter these settings should
 * use hook_form_alter.
 *
 * @param SimpleField $simplefield
 *   The simple_field entity that is being added/edited by this form.
 * @param bool $has_data
 *   Boolean indicating whether this field has data associated with it. This is
 *   used to disable modification of certain settings which cannot be changes
 *   once the field schema becomes unchangeable.
 *
 * @return
 *   A renderable form array which will be appended to the add/edit form. The
 *   form elements must be set up so that the settings can be properly split up
 *   when saved. However you want to structure the form, in the end
 *   $form_state['values'] must contain 'field_settings', 'instance_settings',
 *   'widget_settings' and/or 'formatter_settings' keys, and the values must be
 *   in the right place so they can be properly merged back into their
 *   respecting settings arrays.
 */
function hook_simple_field_type_form($simplefield, $has_data) {
  $form = array();
  $type_info = $simplefield->getTypeInfo();
  $field_settings = $simplefield->getSettings('field');

  switch ($type_info['type']) {
    case 'simple_field_yesno':
      break;
    case 'simple_field_multichoice_single':
    case 'simple_field_multichoice_multi':
      $form['field_settings']['somefieldsetting'] = array(
        '#type' => 'textfield',
        '#title' => t('Field specific setting'),
        '#default_value' => $field_setting['somefieldsetting'],
      );
      break;
    case 'simple_field_short_answer':
    case 'simple_field_long_answer':
    case 'simple_field_single_date':
    case 'simple_field_date_range':
  }

  return $form;
}

/**
 * @} End of "addtogroup hooks".
 */
