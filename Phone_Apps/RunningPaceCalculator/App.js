import React, { useState } from 'react';
import { View, Text, TextInput, Button } from 'react-native';
import { Input } from 'react-native-elements';
import LinearGradient from 'react-native-linear-gradient';

const App = () => {
  const [distance, setDistance] = useState('');
  const [time, setTime] = useState('');
  const [result, setResult] = useState('');

  const calculatePace = () => {
    const distanceNum = parseFloat(distance);
    const timeParts = time.split(':');
    const timeGoal = new Date(0, 0, 0, timeParts[0], timeParts[1], timeParts[2]);
    const totalSeconds = timeGoal.getTime() / 1000;
    const paceSeconds = totalSeconds / distanceNum;

    const paceMinutes = Math.floor(paceSeconds / 60);
    const remainingSeconds = (paceSeconds % 60).toFixed(2);

    setResult(
      `To achieve your goal, you should run each mile in ${paceMinutes} minutes and ${remainingSeconds} seconds.`
    );
  };

  return (
    <View style={{ flex: 1, justifyContent: 'center', padding: 16 }}>
      <LinearGradient
        colors={['#4c669f', '#3b5998', '#192f6a']}
        style={{ padding: 15, alignItems: 'center', borderRadius: 5 }}
      >
        <Text style={{ fontSize: 24, color: 'white', marginBottom: 20 }}>
          Running Pace Calculator
        </Text>
        <Input
          placeholder="Distance (in miles)"
          keyboardType="numeric"
          value={distance}
          onChangeText={setDistance}
          containerStyle={{ marginBottom: 10 }}
        />
        <Input
          placeholder="Time Goal (HH:MM:SS)"
          value={time}
          onChangeText={setTime}
          containerStyle={{ marginBottom: 20 }}
        />
        <Button title="Calculate Pace" onPress={calculatePace} />
      </LinearGradient>
      <Text style={{ marginTop: 20, fontSize: 16 }}>{result}</Text>
    </View>
  );
};

export default App;
