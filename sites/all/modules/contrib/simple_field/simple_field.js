
(function($) {

Drupal.behaviors.simple_field = {
  attach: function(content, settings) {
    if (Drupal.tableDrag['field-overview']) {
      var base = 'field-overview';
      Drupal.tableDrag[base].onDrag = dragHandler(Drupal.tableDrag[base].onDrag);
    }
  }
};

/**
 * Helper to return a modified onDrag handler.
 *
 * The custom handler overrides the 'validIndentInterval' function with a custom
 * version.
 */
function dragHandler(original) {
  return function() {
    this.rowObject.validIndentInterval = validIndentInterval(this.rowObject.validIndentInterval);
    return original.call(this);
  };
}

/**
 * Helper to return a modifies validIndentInterval function.
 *
 * The modifies IndentInterval checks if the item being dragged is allowed to be
 * dragged where it is. If the item is a simple field row, it can only be
 * dragged within it's parent placeholder, and if it is not a simple field row
 * then it cannot be dragged in with the simple fields.
 */
function validIndentInterval(original) {
  return function(prevRow, nextRow) {
    var prev = $(prevRow).hasClass('simple-field-row');
    var next = $(nextRow).hasClass('simple-field-row');
    var indent = $('.indentation', this.element).size();

    if ($(this.element).hasClass('simple-field-row')) {
      if (prev || next) {
        // Lock at current indent if next to a simplefield row.
        return {
          'min': indent,
          'max': indent
        };
      }
      else {
        // Otherwise disable dragging of the row.
        return {
          'min': indent+1,
          'max': indent
        };
      }
    }
    else {

      if ((prev || $(prevRow).hasClass('simple-field-root')) && next) {
        // Disable dragging if dragging inside of simplefield row group.
        return {
          'min': indent+1,
          'max': indent
        };
      }
      else {
        // Return normal ranges.
        indents = original.apply(this, arguments);
        if (prev) {
          // If directly after Simple Fields, cannot be a child either.
          indents.max = Math.min($('.indentation', prevRow).size() - 1, indents.max);
        }
        return indents;
      }
    }
  }
}

})(jQuery);
