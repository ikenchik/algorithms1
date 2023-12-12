// основная функция
function defaultFunction() {
  return "Очень хочу закрыть сессию на 4 и 5";
}

// дополнительные функции
function addFunction1() {
  return "Хорошо отпраздновать новый год";
}

function addFunction2() {
  return "Купить картошки";
}

// основной экспорт модуля
module.exports = defaultFunction;

// дополнительные функции
module.exports.first = addFunction1;
module.exports.second = addFunction2;