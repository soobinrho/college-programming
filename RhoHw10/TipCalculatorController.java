// COSC 211
// Soobin Rho
// July 27, 2022
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.NumberFormat;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import java.math.MathContext;

public class TipCalculatorController {
    /*
     * Controller class for TipCalculator.
    */

    // -------------------------------
    // Formatters
    // -------------------------------
    private static final NumberFormat currency = NumberFormat.getCurrencyInstance();
    private static final NumberFormat percent = NumberFormat.getPercentInstance();
    private BigDecimal tipPercentage = new BigDecimal(0.15);

    // Without this, BigDecimal.divide(...)
    // would sometimes result in
    // "Non-terminating decimal expansion..."
    MathContext roundUp = new MathContext(2, RoundingMode.HALF_UP);

    // -------------------------------
    // gui controls
    // -------------------------------
    @FXML
    private TextField amountTextField;

    @FXML
    private TextField peopleTextField;

    @FXML
    private Label tipPercentageLabel;

    @FXML
    private Slider tipPercentageSlider;

    @FXML
    private TextField tipTextField;

    @FXML
    private TextField tipDividedTextField;

    @FXML
    private TextField totalTextField;

    // -------------------------------
    // Event Handler for Calculate
    // -------------------------------
    @FXML
    private void calculateButtonPressed(ActionEvent event) {
        try {
            BigDecimal amount = new BigDecimal(
                amountTextField.getText());
            BigDecimal people = new BigDecimal(
                peopleTextField.getText());
            BigDecimal tip = amount.multiply(tipPercentage);
            BigDecimal tipDivided = tip.divide(people, roundUp);
            BigDecimal total = amount.add(tip);

            tipTextField.setText(currency.format(tip));
            tipDividedTextField.setText(currency.format(tipDivided));
            totalTextField.setText(currency.format(total));
        }
        catch (NumberFormatException ex) {
            amountTextField.setText("Enter amount and people");
            amountTextField.selectAll();
            amountTextField.requestFocus();
        }
    }

    public void initialize() {
        // -------------------------------
        // Listener for Percentage Slider
        // -------------------------------
        currency.setRoundingMode(RoundingMode.HALF_UP);
        tipPercentageSlider.valueProperty().addListener(
            new ChangeListener<Number>() {
                @Override
                public void changed(
                    ObservableValue<? extends Number> ov,
                    Number oldValue,
                    Number newValue
                ) {
                    tipPercentage = BigDecimal.valueOf(
                        newValue.intValue() / 100.0
                    );
                    tipPercentageLabel.setText(
                        percent.format(tipPercentage)
                    );
                }
            }
        );
    }

}
